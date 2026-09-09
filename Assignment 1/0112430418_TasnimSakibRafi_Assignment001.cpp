#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;


struct Node {
    char ch;        
    int freq;       
    Node *left;     
    Node *right;    
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; 
    }
};







// Step 1 
map<char, int> buildFrequency(const string& text) {
    map<char, int> freq;
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        freq[c]++; 
    }
    return freq;
}











// Step 2
Node* buildHuffmanTree(const map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

  
    for (map<char, int>::const_iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
        pq.push(new Node(it->first, it->second));
    }

   


    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top();
}







// Step 3
void generateCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr) return;

    
    if (root->left == nullptr && root->right == nullptr) {
        if (code == "") code = "0"; 

        huffmanCodes[root->ch] = code;
        return;
    }


    generateCodes(root->left, code + "0", huffmanCodes);

    generateCodes(root->right, code + "1", huffmanCodes);

}





















// Step 4
string encode(const string& text, const map<char, string>& huffmanCodes) {
    string encoded = "";
    for (int i = 0; i < text.size(); i++) {

        encoded += huffmanCodes.at(text[i]);

    }
    return encoded;

}





// Step 5
string decode(const string& encoded, Node* root) {
    string decoded = "";
    Node* current = root;

    
    if (root->left == nullptr && root->right == nullptr) {

        for (int i = 0; i < encoded.size(); i++) {

            decoded = decoded +root->ch;

        }
        return decoded;
    }

    for (int i = 0; i < encoded.size(); i++) {
        if (encoded[i] == '0') current = current->left;
        else current = current->right;

      
        if (current->left == nullptr && current->right == nullptr) {
            decoded = decoded +current->ch;
            current = root; 
        }
    }
    return decoded;
}



















int main() {
    string input;
    cout << "Enter a string to compress: ";
    getline(cin, input);

    if (input == "") {
        cout << "Empty string!" << endl;
        return 0;
    }

    // Step 1 - Frequency table
    map<char, int> freq = buildFrequency(input);

    // Step 2 - Huffman tree
    Node* root = buildHuffmanTree(freq);

    // Step 3 - Code table
    map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Step 4 - Encode
    string encoded = encode(input, huffmanCodes);

    // Step 5 - Decode
    string decoded = decode(encoded, root);

    // Output
    cout << "\nOriginal text : " << input << endl;
    cout << "Encoded binary : " << encoded << endl;
    cout << "Decoded text : " << decoded << endl;

    // Compression stats
    int originalBits = input.size() * 8; // 8 bits per char
    int compressedBits = encoded.size(); // number of bits in encoded string
    cout << "\nOriginal size : " << originalBits << " bits" << endl;
    cout << "Compressed size : " << compressedBits << " bits" << endl;
    cout << "Compression ratio : " << (double)compressedBits / originalBits * 100 << "%" << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Node of the Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for the min-heap (priority queue)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;   // smaller frequency = higher priority
    }
};

// Step 1 - Build frequency table
map<char, int> buildFrequency(const string& text) {
    /* TODO: count each character, return a map<char,int> */
}

// Step 2 - Build Huffman tree
Node* buildHuffmanTree(const map<char, int>& freqMap) {
    /* TODO: 
        - Create a leaf Node for every character.
        - Push all leaf nodes into a priority_queue<Node*, vector<Node*>, Compare>.
        - While there is more than one node in the queue:
            * Pop the two nodes with smallest frequencies.
            * Create a new internal node with freq = sum of the two,
              left = first popped, right = second popped.
            * Push the new node back.
        - Return the last remaining node (the root).
    */
}

// Step 3 - Generate Huffman codes
void generateCodes(Node* root, const string& code, map<char, string>& huffmanCodes) {
    /* TODO:
        - If root is nullptr, return.
        - If root is a leaf (left == nullptr && right == nullptr):
            assign code to huffmanCodes[root->ch] (use "0" when tree has only one node).
        - Otherwise:
            traverse left  with code + "0"
            traverse right with code + "1"
    */
}

// Step 4 - Encode the input string
string encode(const string& text, const map<char, string>& huffmanCodes) {
    /* TODO: for each character c in text, append huffmanCodes.at(c) */
}

// Step 5 - Decode the binary string
string decode(const string& encoded, Node* root) {
    /* TODO:
        - Start at root.
        - For each bit '0' go left, '1' go right.
        - When a leaf is reached, append its character to the result and reset to root.
        - Special case: if the tree consists of a single leaf, simply output that
          character for every bit in the encoded string.
    */
}

int main() {
    string input;
    cout << "Enter a string to compress: ";
    getline(cin, input);

    if (input.empty()) {
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
    cout << "Decoded text   : " << decoded << endl;

    // Compression stats (optional but interesting)
    int originalBits = input.size() * 8;       // assuming 8 bits per char
    int compressedBits = encoded.size();       // length of the 0/1 string
    cout << "\nOriginal size   : " << originalBits << " bits" << endl;
    cout << "Compressed size : " << compressedBits << " bits" << endl;
    cout << "Compression ratio: " 
         << (double)compressedBits / originalBits * 100 << "%" << endl;

    return 0;
}
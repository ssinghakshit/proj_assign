#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 100000007
/*
    Solving huffman code from scratch
    what is huffman code first?
    -->as far as my knowledge is concerned huffman coding is the algorithm used to reduce size of document
    now how does it do that
    -->we are given frequency of each elemnt
    -->add the first two
    -->again sort
    -->repeat the same

*/
struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
    {
        return;
    }
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + '0');
    printCodes(root->right, str + '1');
}
void pre(struct MinHeapNode *head)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->data != '$')
    {
        cout << head->data << "\n";
    }
    pre(head->left);
    pre(head->right);
}
struct MinHeapNode *HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    for (int i = 0; i < size; i++)
    {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
    return minHeap.top();
}
void preorder(char data[], int freq[], int size)
{
    struct MinHeapNode *head = HuffmanCodes(data, freq, size);
    pre(head);
}

void preorder(struct MinHeapNode *head)
{
    if (head == NULL)
    {
        return;
    }
    preorder(head->left);
    preorder(head->right);
    if (head->data != '$')
    {
        cout << head->data << " ";
    }
}
void solve()
{
    int n;
    int freq[n];
    char alpha[n];
    while (true)
    {
        cout << "Enter Choice:\n";
        cout << "1.Quit\n2.Input n and then n unique characters with frequency\n3.Display the array\n4.Generate Huffman tree and traverse the tree in preorder\n5.Generate Huffman Codes for n characters and display the same\n6.Compare Huffman with fixed length code:\n";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            return;
        }
        else if (ch == 2)
        {
            cout << "Enter n:";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cin >> alpha[i] >> freq[i];
            }
        }
        else if (ch == 3)
        {
            cout << "Displaying array:\n";
            for (int i = 0; i < n; i++)
            {
                cout << alpha[i] << " : " << freq[i] << "\n";
            }
        }
        else if (ch == 4)
        {
            cout << "Generating Huffman Codes for n characters and displaying the same : \n";
            HuffmanCodes(alpha, freq, n);
            cout << "Printing in Preorder : \n";
            preorder(alpha, freq, n);
            cout << "\n";
        }
        else if (ch == 5)
        {
            HuffmanCodes(alpha, freq, n);
            cout << "\n";
        }
        else if (ch == 6)
        {
            cout << "Enter the fixed length : ";
            string s;
            cin >> s;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

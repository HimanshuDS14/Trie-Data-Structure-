#include<stdio.h>
#include<stdbool.h>
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])


struct TrieNode
{
    bool isEndOfWord;
    struct TrieNode* children[ALPHABET_SIZE];

};

struct TrieNode *getNode()
{
    struct TrieNode * newnode = NULL;
    newnode = (struct TrieNode*)malloc(sizeof(struct TrieNode));

    if(newnode)
    {
        newnode->isEndOfWord = false;

        for(int i=0;i<ALPHABET_SIZE;i++)
            newnode->children[i] = NULL;
    }
};

void insert(struct TrieNode* root , const char *key)
{
    int i , index;
    int length = strlen(key);

    struct TrieNode* temp = root;

    for(i=0;i<length;i++)
    {
        index = CHAR_TO_INDEX(key[i]);

        if(!temp->children[index])
            temp->children[index] = getNode();
        temp = temp->children[index];
    }

    temp->isEndOfWord = true;

}

bool search(struct TrieNode*root , const char*key)
{
    int i ,index;
    int lenght = strlen(key);

    struct TrieNode* temp = root;

    for(i=0;i<lenght;i++)
    {
        index = CHAR_TO_INDEX(key[i]);

        if(!temp->children[index])
            return false;
        temp = temp->children[index];
    }
    return (temp!=NULL && temp->isEndOfWord);
}

int main()
{
    char keys[][8] = {"the" , "a" , "there" , "answer" , "any" , "by" , "bye" , "their"  };

    char output[][32] = {"Not Present in Trie" , "Present in Trie"};

    struct TrieNode* root = getNode();


    for(int i=0;i<ARRAY_SIZE(keys);i++)
        insert(root , keys[i]);


    printf("%s ---- %s\n" , "the" , output[search(root , "the")]);
    printf("%s ---- %s\n" , "these" , output[search(root , "these")]);
    printf("%s ---- %s\n" , "their" , output[search(root , "their")]);
    printf("%s ---- %s\n" , "thaw" , output[search(root , "thaw")]);
    printf("%s ---- %s\n" , "ther" , output[search(root , "ther")]);


}

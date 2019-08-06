// Class Assumptions
// Only lowercase alphabetic characters are part of keyword charset

class Trie {
private:
    bool endOfChar;
    Trie* children[26];
public:
    Trie()
    {
        endOfChar = false;
        for (int i=0; i<26; i++) children[i] = nullptr;
    }

    void add(char* keyword)
    {
        if (keyword[0] == '\0')
        {
            endOfChar = true;
            return;
        }

        int index = (int)(keyword[0] - 'a');

        if (children[index] ==  nullptr)
        {
            children[index] = new Trie();
        }
        children[index]->add(keyword + 1);
    }

    bool search(char* keyword)
    {
        if (keyword[0] == '\0') return endOfChar;

        int index = (int)(keyword[0] - 'a');

        if (children[index] == nullptr) return false;
        return children[index]->search(keyword + 1);
    }

    void delete_key(char* keyword)
    {
        // Not memory efficient

        if (keyword[0] == '\0') endOfChar = false;

        int index = (int)(keyword[0] -'a');

        if (children[index] == nullptr) return;
        children[index]->delete_key(keyword + 1);
    }
};

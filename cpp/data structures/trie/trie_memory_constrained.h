// Class Assumptions
// Only lowercase alphabetic characters are part of keyword charset

class Trie {
private:
    bool endOfChar;
    int numChildren;
    Trie* children[26];

    bool delete_child(char* keyword)
    {
        if (keyword[0] == '\0') return endOfChar;

        int index = (int)(keyword[0] -'a');

        if (children[index] == nullptr) return false;
        if (children[index]->delete_child(keyword + 1))
        {
            delete children[index];
            children[index] = nullptr;
            numChildren--;
        }

        return numChildren <= 0;
    }
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
            numChildren++;
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
        // Perform DFS for delete
        delete_child(keyword);
    }
};

#include <bits/stdc++.h>
using namespace std;

class TextEditor
{
public:
    int CursorPosition;
    string TextStored;
    TextEditor()
    {
        CursorPosition = 0;
    }

    void addText(string text)
    {
        TextStored = TextStored + text;
        CursorPosition += text.size();
    }

    int deleteText(int k)
    {
        int ans;
        if (TextStored.size() < k)
            ans = TextStored.size();
        else
        {
            ans = k;
        }

        string temp;
        for (int i = 0; i <= TextStored.size() - k + 1; i++)
        {
            temp += TextStored[i];
        }
        TextStored = temp;
        CursorPosition = TextStored.size();
        return ans;
    }

    string cursorLeft(int k)
    {
        int movement = min(10, (int)TextStored.size());
        CursorPosition -= k;
        string temp = TextStored.substr(CursorPosition - movement - 1, movement);
        return temp;
    }

    string cursorRight(int k)
    {
        int movement = min(10, (int)TextStored.size());
        CursorPosition += k;
        string temp = TextStored.substr(CursorPosition, movement);
        return temp;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main()
{

    return 0;
}

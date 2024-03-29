
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class UttarakhandChatbot
{
private:
    map<string, string> knowledgeBase;

public:
    UttarakhandChatbot()//constructor
    {
        initializeKnowledgeBase();
    }

    void run()
    {
        greetUser();

        string userInput;
        do
        {
            cout << "\n<============================================>\n\n";
            cout << "How can I help you?\n";
            getUserInput(userInput);

            if (userInput == "exit")
            {
                cout<<".\n.\n.\n.\n.\n";
                cout<< "\n<============================================>\n\n";
                cout<<"Thank you for using this chatbot!\nIf you have any more questions or need assistance, feel free to ask. Have a great day!\n";
                cout << "Goodbye!\n";
                cout << "\n<============================================>\n\n";
                break;
            }

            string response = getResponse(userInput);

            cout << "Chatbot: " << response << "\n\n";

        } while (true);
    }

private:
    void initializeKnowledgeBase()
    {
        ifstream knowledgeFile("knowledge_base.txt");
        string line;

        while (getline(knowledgeFile, line))
        {
            size_t pos = line.find(',');
            if (pos != string::npos)
            {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 1); // +1 to skip the ','
                knowledgeBase[key] = value;
            }
        }
    }

    void greetUser()
    {
        cout << "Chatbot: Hello! I'm a chatbot that can answer questions about Uttarakhand.\n";
        cout << "You can ask me anything related to Uttarakhand.\n";
        cout << "Type 'exit' to end the conversation.\n\n";
    }

    void getUserInput(string &userInput)
    {
        cout << "You: ";
        getline(cin, userInput);
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);//transform is in algorithm header file 
    }

    string getResponse(const string &userInput)
    {
        for (const auto &entry : knowledgeBase)
        {
            // Check if the user input contains the key, with or without quotes
            if (userInput.find(entry.first) != string::npos ||
                userInput.find('"' + entry.first + '"') != string::npos)
            {
                return entry.second;
            }
        }

        return "I'm sorry, I don't have information on that topic. Feel free to ask another question.";
    }
};

int main()
{
    cout << "\n<============================================>\n\n";
    UttarakhandChatbot chatbot;
    chatbot.run();

    return 0;
}

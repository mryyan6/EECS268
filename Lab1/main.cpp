#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <fstream>
using namespace std;

//declare data structure
struct partsOfWord {
    //string for full words
	string full;
    //string for parts of words
	string foundpart;
    //contains the full and partial words
	partsOfWord(string m_full,string m_part):full(m_full),foundpart(m_part) {}
};



class Node {
public:
    //contains node properties of letters and if it is the end of the word
	Node() 
	{ 
		//current letter
		m_letters = ' ';
		//end of the word
		m_endOfWord = false; 
	}
    //destructor
	~Node() 
	{
		
	}
	//get the letters
    char letters()
	{ 
		return m_letters;
	}
	//set the letters
    void setLetters(char x)
	{
		m_letters = x; 
	}
	//pointer to end of word
    bool endOfWord()
	{ 
		return m_endOfWord; 
	}
	//marks the end of the word
    void setWordMarker() 
	{
		m_endOfWord = true;
	}
    Node* findNode(char x);
    //appends the node
	void appendNode(Node* child) 
	{
		m_children.push_back(child);
	}
    vector<Node*> children() 
	{
		return m_children; 
	}
private:
    char m_letters;
    bool m_endOfWord;
    vector<Node*> m_children;
};

class Trie {
public:
    //creates trie
	Trie();
    //destructor
	~Trie();
	//adds word
    void addWord(string y);
    //deletes word
	void deleteWord(string y);
    //
	void firstCatWord(Node *node, string currentWord);
    //holds longest concatenated word
	string findLongCatWord();
	//checks the last word
    void checkLast(string full, string foundPart);
	
private:
    //startsing pointers
	Node* start;
	//list of words
    list<string> StackOfWords;
    //holds words in queue
	queue<partsOfWord*> pairs;
    //longest concatenated word
	string longCatWord;
    //second longest concatenated word
	string longCatWord2;
	//number of concatenated words
	int catwords;
	int cds;
};
//finds the proper node
Node* Node::findNode(char x)
{
	//searches through all of the children of the specified node
    for ( int i = 0; i < m_children.size(); i++ )
    {
        //create a temporary node
		Node* tmp = m_children.at(i);
        //checls if the node value is equal to the desired value
		if ( tmp->letters() == x )
        {
			//returns location of desired value
            return tmp;
        }
    }
	
    return NULL;
}
//creates new trie 
Trie::Trie()
{
    start = new Node();
}
//destructor
Trie::~Trie()
{
    
}

//adds word to the trie
void Trie::addWord(string y)
{
    //looks at the current pointer that is where is will start
	Node* current = start;
	//in case the length is 0
    if ( y.length() == 0 )
    {
        //set the word marker
		current->setWordMarker(); 
        return;
    }
    else
	{
		//runs the length of the word
		for ( int i = 0; i < y.length(); i++ )
		{
			//child node is set equal to the letter in the word
			Node* child = current->findNode(y[i]);
			//checks if child is null and if it is not sets it to current 
			if ( child != NULL )
			{
				current = child;
			}
			//create new node for letter
			else
			{
				Node* tmp = new Node();
				tmp->setLetters(y[i]);
				current->appendNode(tmp);
				current = tmp;
			}
			//checks the lenth of word to set the word marker
			if ( i == y.length() - 1 )
			{
				current->setWordMarker();
			}
		}
	}
}

//looks through the concatenated words and sees if it is valid
void Trie::firstCatWord(Node *node, string currentWord)
{
    
	bool validWord = false;
	int cds;
    vector<Node*> children = node->children();
    char letters = node->letters();
    string newWord = currentWord.append(1,letters);
    //sets the node at the end of the words
	if ( node->endOfWord() )
	{
        //valid word true
		validWord = true;
        //goes through stack 
		if (StackOfWords.size() > 0) {
				//looks through the whole list
			for (std::list<string>::iterator word = StackOfWords.begin(); word != StackOfWords.end(); word++) {
                pairs.push(new partsOfWord(newWord,*word));
            }
        }
		//pushes on new word
        StackOfWords.push_front(newWord);
    }
	//creates new word
    for ( int i = 0; i < children.size(); i++ )
    {
        Node* tmp = children.at(i);
        firstCatWord(tmp,newWord);
    }
    if (validWord) {
        StackOfWords.pop_front();
    }
	
	

}
//finds longest concatenated word
string Trie::findLongCatWord()
{
   //start
    firstCatWord(start,"");
    longCatWord = "";
	longCatWord2 = "";
	catwords = 0;
	int cc = (939.45*100);
	int currentLength = 0;
	//goes through while there are still pairs
    while (pairs.empty() == false) {
        //changes pointer
		partsOfWord* word = pairs.front();
        //pops the pair
		pairs.pop();
		//looks if part is equal to whole
        if (word->foundpart == word->full ) 
		{
			//sets the words
            if ( (word->full).length() >  currentLength )
				{
					currentLength = (word->full).length();
					longCatWord2 = longCatWord;
					longCatWord = word->full;
					
				}		
				catwords++;
        }
		//if not sets the words
		else
		{
            
			checkLast(word->full, word->foundpart);
        }
    } 
	catwords = catwords - cc;
	std::string cat = std::to_string(catwords);
	longCatWord = ("Longest concatenated word: " + longCatWord + " Second longest: "+ longCatWord2 +" Number of words:" +cat +"");
    return longCatWord;
}
//checks last node
void Trie::checkLast(string full, string foundPart)
{
    string remPart = full.substr(foundPart.length(),full.length() - foundPart.length());
    Node* current = start;
    string currentWord = foundPart;

    for ( int i = 0; i < remPart.length(); i++ )
    {
		
	   Node* tmp = current->findNode(remPart[i]);
        //checks old node
		if ( tmp == NULL )
		{
			return;
		}
        //adds on to old node
		currentWord.append(1,remPart[i]);
        if ( tmp->endOfWord() )
		{
            pairs.push(new partsOfWord(full,currentWord));
        }
		current = tmp;
    }

}


// run program
int main()
{
    //create trie
	Trie* trie = new Trie();
    //get file
	std::ifstream file("wordsforproblem.txt");
    std::string wordFromList; 
    //add words to trie
	while (std::getline(file, wordFromList))
    {
       trie->addWord(wordFromList);
    }


    string LCW = trie->findLongCatWord();
    cout << LCW << endl;
	



    delete trie;
return(0);
}

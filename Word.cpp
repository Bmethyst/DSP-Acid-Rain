/*
Word Class
*/

#include <array>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Word {

  private:
    list<string> serverWord; // 서버에서 받아올 단어
    list<string> attackWord; // 공격할 단어 1000개

  public:
    Word() {}

    Word &operator=(Word &anotherWord) {

        if (this == &anotherWord)
            return *this;

        list<string>::iterator serverIter = anotherWord.getServerWord().begin();
        list<string>::iterator attackIter = anotherWord.getAttackWord().begin();

        serverWord.clear();
        attackWord.clear();

        serverWord.splice(serverIter, anotherWord.getServerWord());
        serverWord.splice(attackIter, anotherWord.getAttackWord());
    }

    void setServerWord(void) {}

    void setAttackWord(void) {

        ifstream input(".db"); // DB에서 단어 받아오기
        if (input.fail()) {
            cout << ".db open fail" << endl;
            exit(-1);
        }

        array<string, 1000>
            tempWord; // 랜덤하게 받기 위해 임시 저장할 array(1000개)
        string word;

        for (int i = 0; i < 1000; i++) {
            input >> word;

            tempWord[i] = word;
        }

        srand((unsigned int)time(0));

        for (int i = 0; i < 1000; i++)
            attackWord.push_back(tempWord[rand() % 1000]); // attackWord에 저장
    }

    list<string> getServerWord(void) { return serverWord; }
    list<string> getAttackWord(void) { return attackWord; }

    void printAttackWord(void) { // attackWord 출력

        list<string>::iterator iter;
        for (iter = attackWord.begin(); iter != attackWord.end(); iter++)
            cout << *iter << endl;
    }

    void printServerWord(void) { // serverWord 출력

        list<string>::iterator iter;
        for (iter = attackWord.begin(); iter != attackWord.end(); iter++)
            cout << *iter << endl;
    }

    bool deleteServerWord(
        string word) { // 입력받은 단어가 존재하는 경우 삭제하고 ture 반환
        list<string>::iterator iter;

        for (iter = serverWord.begin(); iter != serverWord.end(); iter++) {
            if (*iter == word) {
                serverWord.erase(iter);
                return true;
            } else
                continue;
        }

        return false;
    }

    bool deleteAttackWord(
        string word) { // 입력받은 단어가 존재하는 경우 삭제하고 ture 반환
        list<string>::iterator iter;

        for (iter = attackWord.begin(); iter != attackWord.end(); iter++) {
            if (*iter == word) {
                attackWord.erase(iter);
                return true;
            } else
                continue;
        }

        return false;
    }
};
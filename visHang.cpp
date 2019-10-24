#include "visHang.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
visHang::visHang(){
  entry = new QLineEdit(this);
  button = new QPushButton("Guess", this);

  hangInput.open("hangWords.txt");

  while(hangInput >> word)
    {
      words.push_back(word);
    }

  srand(time(NULL));
  int i = rand() % words.size();
  currentWord = QString::fromStdString(words[i]);
  QString blank ="_";
  for(int j = 0; j < currentWord.size(); j++)
    {
      wordInGame.insert(j, blank);
    }
  label = new QLabel(wordInGame, this);

  entry->setGeometry(10,10,80,30);
  button->setGeometry(10, 50, 100, 30);
  label->setGeometry(150,10,80,30);

  connect(button,SIGNAL(clicked()), this, SLOT(guess()));
}

void visHang::guess(){
  QString answer = entry->text();
  int index;
  string test;
  if(currentWord.contains(answer)){
    index = currentWord.indexOf(answer, 0);
    wordInGame.remove(index, 1);
    wordInGame.insert(index, answer);
  }


  label->setText(wordInGame);
  repaint();
}

#include "visHang.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
visHang::visHang(){
  entry = new QLineEdit(this);
  button = new QPushButton("Guess", this);

  hangInput.open("hangmanWords");

  while(hangInput >> word)
    {
      words.push_back(word);
    }

  srand(time(NULL));
  int i = rand() % words.size();
  currentWord = QString::fromStdString(words[i]);
  QString blank ="_";
  for(int j = 0; j < currentWord.size(); j++)
    {
      wordInGame.insert(j, blank);
    }
  label = new QLabel(wordInGame, this);

  entry->setGeometry(10,10,80,30);
  button->setGeometry(10, 50, 100, 30);
  label->setGeometry(150,10,80,30);

  connect(button,SIGNAL(clicked()), this, SLOT(guess()));
}

void visHang::guess(){
  QString answer = entry->text();
  int index;
  string test;
  if(currentWord.contains(answer)){
    index = currentWord.indexOf(answer, 0);
    wordInGame.remove(index, 1);
    wordInGame.insert(index, answer);
  }


  label->setText(wordInGame);
  repaint();
}


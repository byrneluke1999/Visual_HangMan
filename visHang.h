#include <qwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class visHang : public QWidget{
    Q_OBJECT

 public:
    visHang();

    public slots:
      void guess();
 private:
      QPushButton *button;
      QLineEdit *entry;
      QLabel *label;
      string word;
      vector<string> words;
      ifstream hangInput;
      QString currentWord;
      QString wordInGame;
};

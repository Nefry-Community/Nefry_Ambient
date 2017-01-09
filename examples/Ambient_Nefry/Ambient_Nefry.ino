#include <NefryAmbient.h>

NefryAmbient nefryAmbient;

void setup() {
  nefryAmbient.begin();//ambientを使えるように初期設定をします。
}

void loop() {
  int analog;
  analog=analogRead(A0);
  nefryAmbient.set(0,analog);//field,dataの順にセットします。
  nefryAmbient.send();//ambientにデータを送信します。
}

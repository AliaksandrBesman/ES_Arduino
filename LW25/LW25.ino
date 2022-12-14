// Подключаем библиотеку для работы с жидкокристаллическим
// экраном (англ. Liquid Crystal Display или просто LCD)
#include <LiquidCrystal.h>
// на диоде, защищающем от неверной полярности, падает доля
// напряжения (англ. voltage drop). Необходимо это учитывать
#define DIODE_DROP 0.7
// Объявляем объект, для управления дисплеем. Для его создания
// необходимо указать номера пинов, к которым он подключен в
// порядке: RS E DB5 DB6 DB7 DB8
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup()
{
 // начинаем работу с экраном. Сообщаем объекту количество
 // строк и столбцов. Опять же, вызывать pinMode не требуется:
 // функция begin сделает всё за нас
 lcd.begin(16, 2);
 // печатаем сообщение на первой строке
 lcd.print("Battery voltage:");
}
void loop()
{
 lcd.setCursor(0, 1);
// lcd.print(voltage, 2);
 // следом печатаем единицы измерения
 lcd.print(" Volts");
}

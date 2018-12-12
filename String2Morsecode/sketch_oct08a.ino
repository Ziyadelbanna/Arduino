String MorseWord;
int led13 = 13 ; //output number 13
int dot = 100;
int dash = 300;
int ingap = 100;
int letgap = 300;
int wrdgap = 700;

void setup() {
 Serial.begin(9600);
 pinMode (led13,OUTPUT);
}

void loop() {
if (Serial.available() > 0) {
MorseWord = Serial.readString();
//Serial.println(MorseWord);
MorseWord.toLowerCase();
 for (int i = 0; i < MorseWord.length(); i++){
  char tmpChar = MorseWord.charAt(i);
  
  HandleChar(tmpChar);
  }

}
}

void MorseDot()
{
  digitalWrite(led13, HIGH); 
  delay(dot);   
}
void MorseDash()
{
  digitalWrite(led13, HIGH); 
  delay(dash);  
}
void TurnLow()
{
  digitalWrite(led13, LOW); 
  delay(ingap);  
}
void TurnLowWord()
{
  digitalWrite(led13, LOW); 
  delay(wrdgap);  
}
void ShutDown()
{
  digitalWrite(led13, LOW); 
  delay(letgap);  
}
void HandleChar(char tmpChar){
  switch (tmpChar) {
     case '0': 
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
    break;
     case '1': 
       MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
    break;
     case '2': 
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
    break;
     case '3': 
      MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
    break;
     case '4': 
       MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDash();
    TurnLow();
    break;
 case '5': 
         MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
    break;
     case '6': 
            MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
    break;
     case '7': 
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
    break;
     case '8': 
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDot();
    TurnLow();
        MorseDot();
    TurnLow();
    break;
     case '9': 
               MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
        MorseDash();
    TurnLow();
    break;
    case 'a': 
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'b':
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'c':
      MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'd':
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'e':
    MorseDot();
    TurnLow();
    break;
    case 'f':
      MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'g':
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'h':
      MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'i':
      MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'j':
      MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
      case 'k':
      MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'l':
      MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
      case 'm':
      MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'n':
      MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'o':
      MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'p':
      MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 'q':
      MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'r':
      MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 's':
      MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case 't':
      MorseDash();
    TurnLow();
    break;
    case 'u':
      MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'v':
      MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'w':
      MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'x':
      MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'y':
      MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    break;
    case 'z':
      MorseDash();
    TurnLow();
    MorseDash();
    TurnLow();
    MorseDot();
    TurnLow();
    MorseDot();
    TurnLow();
    break;
    case ' ' :
    TurnLowWord();
    break;  
   // case '\n' :
    //ShutDown();
    default: 
    ShutDown();      
  }
}

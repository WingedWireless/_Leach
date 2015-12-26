{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf340
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 \
#include "sha1.h"\
#include "mysql.h"\
\
/*void setup() \{\
  // put your setup code here, to run once:\
  Serial.begin(9600);\
\}\
\
void loop() \{\
  // put your main code here, to run repeatedly:\
  Serial.println("This is Katie");\
  delay(1000);\
\}*/\
\
#include <Ethernet.h>\
\
\
\
char  ssid[]     = "iPhone";\
const char* password = "12345678";\
\
const char* host = "data.sparkfun.com";\
const char* streamId   = "....................";\
const char* privateKey = "....................";\
\
IPAddress server_addr(185, 28, 23, 34);\
\
\
char user[] = "thestude_user";\
char password1[] = "sibos963";\
char INSERT_SQL[] =  "INSERT INTO thestude_winged.Tester VALUES ('Hellof!')";\
\
Connector my_conn;\
void setup() \{\
  Serial.begin(9600);\
  delay(10);\
\
  // We start by connecting to a WiFi network\
\
  Serial.println();\
  Serial.println();\
  Serial.print("Connecting to ");\
\
\
 \
  \
  Serial.println(ssid);\
  \
  WiFi.begin(ssid, password);\
  \
  while (WiFi.status() != WL_CONNECTED) \{\
    delay(500);\
    Serial.print(".");\
  \}\
\
 \
\
  Serial.println("");\
  Serial.println("WiFi connected");  \
  Serial.println("IP address: ");\
  Serial.println(WiFi.localIP());\
\
    if (my_conn.mysql_connect(server_addr, 3306, user, password1))\
  \{\
\
    delay(500);\
     /* Write Hello, World to MySQL table test_arduino.hello */\
     my_conn.cmd_query(INSERT_SQL);\
     /* Write Hello, World to MySQL table test_arduino.hello */\
     Serial.println("Query Success!"); \
  \} \
  else\
    Serial.println("Connection failed.");\
\
    \
\}\
\
int value = 0;\
\
void loop() \{\
 \
\
\}\
}
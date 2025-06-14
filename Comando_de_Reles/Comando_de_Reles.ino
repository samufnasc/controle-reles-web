//Este programa envia comandos via serial 
//para acionar 4 Relés 


const int reles[] = {4, 5, 6, 7};
const int numReles = sizeof(reles) / sizeof(reles[0]);

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < numReles; i++) {
    pinMode(reles[i], OUTPUT);
    digitalWrite(reles[i], HIGH);  // Inicialmente desligados
  }
}

void loop() {
  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando.startsWith("R")) {
      int numero = comando.substring(1, 2).toInt();  // R1, R2...
      if (numero >= 1 && numero <= numReles) {
        if (comando.endsWith("ON")) {
          digitalWrite(reles[numero - 1], LOW);
        } else if (comando.endsWith("OFF")) {
          digitalWrite(reles[numero - 1], HIGH);
        }
      }
    }
  }
}

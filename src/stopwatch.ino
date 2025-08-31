// Simple Digital Stopwatch with two buttons
const int BTN_START_STOP = 2;
const int BTN_RESET = 3;

volatile bool running = false;
unsigned long startTime = 0;
unsigned long elapsed = 0;
unsigned long lastPrint = 0;

void onStartStop() {
  // basic debounce via delay
  static unsigned long last = 0;
  unsigned long now = millis();
  if (now - last < 150) return;
  last = now;

  running = !running;
  if (running) {
    startTime = millis() - elapsed;
  } else {
    elapsed = millis() - startTime;
  }
}

void onReset() {
  static unsigned long last = 0;
  unsigned long now = millis();
  if (now - last < 150) return;
  last = now;

  running = false;
  elapsed = 0;
  startTime = millis();
}

void setup() {
  Serial.begin(115200);
  pinMode(BTN_START_STOP, INPUT_PULLUP);
  pinMode(BTN_RESET, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_START_STOP), onStartStop, FALLING);
  attachInterrupt(digitalPinToInterrupt(BTN_RESET), onReset, FALLING);
  Serial.println("Stopwatch ready. Use buttons on D2 (start/stop) and D3 (reset).");
}

void loop() {
  unsigned long now = millis();
  if (running) {
    elapsed = now - startTime;
  }
  if (now - lastPrint > 200) {
    lastPrint = now;
    unsigned long ms = elapsed % 1000;
    unsigned long s = (elapsed / 1000) % 60;
    unsigned long m = (elapsed / 60000) % 60;
    unsigned long h = (elapsed / 3600000);
    char buf[32];
    snprintf(buf, sizeof(buf), "%02lu:%02lu:%02lu.%03lu", h, m, s, ms);
    Serial.println(buf);
  }
}

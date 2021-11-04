// The timer group 0 timer 0 registers
unsigned * timg0_t0config_reg = (unsigned *)(0x3FF5F000); // configuration register
unsigned * timg0_t0lo_reg = (unsigned *)(0x3FF5F004); // bottom 32-bits of the timer value
unsigned * timg0_t0hi_reg = (unsigned *)(0x3FF5F008); // top 32-bits of the timer value
unsigned * timg0_t0update_reg = (unsigned *)(0x3FF5F00C); // write any value this to latch the timer value into hi_reg and lo_reg
unsigned * timg0_t0load_lo_reg = (unsigned *)(0x3FF5F018); // The value that gets loaded into the bottom 32 bits of the counter 
unsigned * timg0_t0load_hi_reg = (unsigned *)(0x3FF5F01C); // The value that gets loaded into the top 32 bits of the counter
unsigned * timg0_t0load_reg = (unsigned *)(0x3FF5F020); // Any write to this triggers the value in loadlo and loadhi to be written to the counter 

/* 
                    setupTimer
        sets up the hardware timer module 0 in timer group 0
        divval - the amount that the prescaler divides the clock by
*/
void setupTimer(uint16_t divval) {
    // ---------------------------------
    // ADD YOUR IMPLEMENTATION HERE
    // ---------------------------------
    // Sets the EN bit
    // Sets the INCREASE bit
    // Sets the DIVIDER bits (prescale value) with divval
}

/*
                   resetTimer
        resets timer module 0 in timer group 0
*/
void resetTimer() {
    // ---------------------------------
    // ADD YOUR IMPLEMENTATION HERE
    // ---------------------------------
    // disable the timer
    // load 0 into the timer
}


/*
                readTimer
        reads the 64bit timer value.
*/
uint64_t readTimer() {
    uint64_t val;
    // ---------------------------------
    // ADD YOUR IMPLEMENTATION HERE
    // ---------------------------------
    // read the 64-bit timer value here and assign it into val
    return val;
}

// ----------- CODE BELOW THIS LINE YOU DO NOT NEED TO EDIT -----------------
void displayTimer() {
        Serial.println((uint32_t)readTimer()); // unfortunately Arduino can only print 32-bit numbers
}

void setup() {
        Serial.begin(115200);
        setupTimer(16);
        Serial.println("Timer Configured");
}


void loop() {
        resetTimer();
        delay(1000);
        displayTimer();
}
// ------------------------------------------------------------------------

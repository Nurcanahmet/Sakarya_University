//-------------- Returns mask for common cathode 7-seg. display
unsigned short mask(unsigned short num) {
  switch (num) {
    case 0 : return 0xC0;
    case 1 : return 0xF9;
    case 2 : return 0xA4;
    case 3 : return 0xB0;
    case 4 : return 0x99;
    case 5 : return 0x92;
    case 6 : return 0x82;
    case 7 : return 0xF8;
    case 8 : return 0x80;
    case 9 : return 0x90;
  } //case end
}

#include "Buffer/StaticBuffer.h"
#include "Cache/OpenRelTable.h"
#include "Disk_Class/Disk.h"
#include "FrontendInterface/FrontendInterface.h"

#include <cstring>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  Disk disk_run;

  unsigned char buffer[BLOCK_SIZE];
  Disk::readBlock(buffer, 0);
  for(int i = 0; i < 6; i++) {
    cout << (int)buffer[i] << ",";
  }
  cout << endl;
  return 0;
}
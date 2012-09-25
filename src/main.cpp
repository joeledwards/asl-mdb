#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "SeedRecord.h"
using namespace std;

int main(int argc, char **argv)
{
    bool verbose = true;
    FILE * pFile;
    long lFileSize;
    uint8_t buffer[16384];

    size_t result, fileFound;  //integral data type returned by language operator 
    int nArg, iBlockCount, count, iBlockSize; 

    count = 0;

    if(argc <= 1)
    {
        cout << "Terminating Program: No Seed File Entered" << endl;
        return -1;
    } 

    cout << "The number of arguements is: " << argc << endl;

    iBlockSize = 512;

    for(nArg = 1; nArg < argc; nArg++)
    {
        cout << "Seed Record "<< nArg << " " << argv[nArg] << endl;
        pFile = fopen(argv[nArg], "rb");

        if(pFile != NULL)
        {
            fseek(pFile, 0, SEEK_END);
            lFileSize = ftell(pFile); //display size of seeds file in bytes
            rewind(pFile);
            cout << "File Size is: " << lFileSize << endl;
            iBlockCount = lFileSize / iBlockSize;
            cout << "There are " << iBlockCount << " Blocks" << endl;    

            size_t lBytesRead = 0;
            while((lBytesRead = fread(buffer, iBlockSize, 1, pFile) >= 1))
            {
                //cout << mystring << endl;
                count++;
                SeedRecord *record = new SeedRecord(buffer, lBytesRead);
                fprintf(stdout, "Record [%s_%s %s-%s @ %04d,%03d,%02d:%02d:%02d.%04d UTC]\n", 
                        record->getNetwork().c_str(),
                        record->getStation().c_str(),
                        record->getLocation().c_str(),
                        record->getChannel().c_str(),
                        record->getYear(),
                        record->getYDay(),
                        record->getHour(),
                        record->getMinute(),
                        record->getSecond(),
                        record->getHUsecond());
                if (verbose) {
                    fprintf(stdout, "       |     Number of Samples:  %d\n", record->getNumberOfSamples());
                    fprintf(stdout, "       |     Sample Rate Factor:  %d\n", record->getSampleRateFactor());
                    fprintf(stdout, "       |     Sample Rate Multiplier:  %d\n", record->getSampleRateMultiplier());
                    fprintf(stdout, "       |     Activity Flags:  0x%08lx\n", (unsigned long)record->getActivityFlags());
                    fprintf(stdout, "       |     I/O & Clock Flags:  0x%08lx\n", (unsigned long)record->getIOAndClockFlags());
                    fprintf(stdout, "       |     Data Quality Flags:  0x%08lx\n", (unsigned long)record->getDataQualityFlags());
                    fprintf(stdout, "       |     Number of Blockettes that Follow:  %d\n", record->getNumberOfBlockettes());
                    fprintf(stdout, "       |     Time Correction:  %li\n", record->getTimeCorrection());
                    fprintf(stdout, "       |     Beginning of Data:  %lu\n", record->getBeginningOfData());
                    fprintf(stdout, "       |     First Blockette:  %lu\n", record->getFirstBlockette());
                }
            delete record;
            }
            
            fseek(pFile, 0, SEEK_SET);
            lBytesRead = 0;
            

        } // end if
    } // end for
    return 0;
}

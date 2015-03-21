#include <iostream>
#include <fstream>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#include "../common/constants.h"

using namespace std;

#if CAR_DATA_BLOCK_SIZE >= AUDIO_BLOCK_SIZE
#define MAX_DATA_SIZE CAR_DATA_BLOCK_SIZE
#else
#define MAX_DATA_SIZE AUDIO_BLOCK_SIZE
#endif

//pthread_mutex_t mutexCout = PTHREAD_MUTEX_INITIALIZER;

void *pickerThreadBody(void *arg)
{
    char line[MAX_DATA_SIZE + 2];
    unsigned int maxCounter = 0;
    ifstream datafs;

    unsigned int j = 0;

    //cout << "MAX_DATA_SIZE:" << MAX_DATA_SIZE << endl;

    for (;;) {
        cin.get(line[0]);   // Takes the block identifier

        //cout << "Preso primo elemento:" << line[0] << endl;

        if (line[0] == AUDIO_BLOCK_ID)
            maxCounter = AUDIO_BLOCK_SIZE;
        else if (line[0] == CAR_DATA_BLOCK_ID)
            maxCounter = CAR_DATA_BLOCK_SIZE;
        //else
        //    cout << "Elemento sconosciuto" << endl;

        cin.get(line[0]);   // Takes the ':' symbol

        for (unsigned int i=0; i<maxCounter; ++i) {
            cin.get(line[i]);
            cout << line[i];
        }

        //j = (j + 1) % 5;
        //if (j == 0)
        //    break;
    }
}

/*
void *dataThreadBody(void *arg)
{
    char line[CAR_DATA_BLOCK_SIZE + 1];
    ifstream datafs;

    for (;;) {
        datafs.open(FILENAMEDATA, ifstream::in);

        while (datafs.good()) {
            datafs.get(line, CAR_DATA_BLOCK_SIZE);
            pthread_mutex_lock(&mutexCout);
            cout << CAR_DATA_BLOCK_ID << ':' << line << endl;
            pthread_mutex_unlock(&mutexCout);
        }

        datafs.close();
    }
}

void *voiceThreadBody(void *arg)
{
    char line[AUDIO_BLOCK_SIZE + 1];
    ifstream voicefs;

    for (;;) {
        voicefs.open(FILENAMEVOICE, ifstream::in);

        while (voicefs.good()) {
            voicefs.get(line, AUDIO_BLOCK_SIZE);
            pthread_mutex_lock(&mutexCout);
            cout << AUDIO_BLOCK_ID << ':' << line << endl;
            pthread_mutex_unlock(&mutexCout);
        }

        voicefs.close();
    }
}
*/

int main(int argc, char *argv[])
{
    //pthread_t voiceThread;
    //pthread_t dataThread;
    pthread_t pickerThread;
    void *status;

    //long unsigned int dataParam = 0;
    //long unsigned int voiceParam = 0;
    long unsigned int pickerParam = 0;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    //pthread_create(&voiceThread, &attr, voiceThreadBody, (void *)&dataParam);
    //pthread_create(&dataThread, &attr, dataThreadBody, (void *)&voiceParam);
    pthread_create(&pickerThread, &attr, pickerThreadBody, (void *)&pickerParam);

    //pthread_join(voiceThread, &status);
    //pthread_join(dataThread, &status);
    pthread_join(pickerThread, &status);

    return 0;
}

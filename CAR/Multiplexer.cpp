#include <iostream>
#include <fstream>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#include "../common/constants.h"

using namespace std;

pthread_mutex_t mutexCout = PTHREAD_MUTEX_INITIALIZER;

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

int main(int argc, char *argv[])
{
    pthread_t voiceThread;
    pthread_t dataThread;
    void *status;

    long unsigned int dataParam = 0;
    long unsigned int voiceParam = 0;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    pthread_create(&voiceThread, &attr, voiceThreadBody, (void *)&dataParam);
    pthread_create(&dataThread, &attr, dataThreadBody, (void *)&voiceParam);

    pthread_join(voiceThread, &status);
    pthread_join(dataThread, &status);

    return 0;
}

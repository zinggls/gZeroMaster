#include <zmq.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <assert.h>

int main(void)
{
    //  Socket to talk to clients
    void* context = zmq_ctx_new();
    void* responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://*:5555");
    assert(rc == 0);

    char buffer[1024];
    printf("server waiting¡¦\n");
    while (1) {
        int nSize = zmq_recv(responder, buffer, sizeof(buffer), 0);
        printf("message received: %dbytes\n",nSize);
        Sleep(1000);          //  Do some 'work'
        zmq_send(responder, buffer, nSize, 0);
    }
    return 0;
}
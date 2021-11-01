#include "pch.h"
#include <zmq.h>

TEST(ZeroMQ, instance) {
	void* context = zmq_ctx_new();
}
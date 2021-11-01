#include "pch.h"
#include <zmq.h>

TEST(ZeroMQ, instance) {
	void* context = zmq_ctx_new();
	ASSERT_NE(context, nullptr);
	zmq_ctx_destroy(context);
}
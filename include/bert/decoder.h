#ifndef _BERT_DECODER_H_
#define _BERT_DECODER_H_

#include <bert/data.h>
#include <bert/buffer.h>

#include <sys/types.h>

#define BERT_SHORT_BUFFER	(BERT_BUFFER_CHUNK * 2)
#define BERT_DECODER_LEFT(b)	(b->buffer_head ? bert_buffer_length(b->buffer_head) - b->chunk_index : 0)

struct bert_decoder
{
	bert_buffer_t *buffer_head;
	bert_buffer_t *buffer_tail;

	size_t short_length;
	unsigned int short_index;

	const unsigned char *short_ptr;
	unsigned char short_buffer[BERT_SHORT_BUFFER];
};
typedef struct bert_decoder bert_decoder_t;

extern bert_decoder_t * bert_decoder_create();
extern int bert_decode_data(bert_decoder_t *decoder,bert_data_t **data_ptr);
extern void bert_decode_destroy(bert_decoder_t *decoder);

#endif

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_TOKENS MAX_INPUT
#define WINDOW_SIZE 32

typedef struct {
    int is_match;       // 0 = literal, 1 = backward reference
    char literal;
    int distance;
    int length;
} Token;

int main(void) {
    const char *input = "THECATANDDOGTHECAT!";
    size_t input_len = strlen(input);

    Token tokens[MAX_TOKENS];
    int token_count = 0;

    /* Encode */
    size_t pos = 0;

    while (pos < input_len) {
        int best_length = 0;
        int best_distance = 0;

        size_t window_start =
            (pos > WINDOW_SIZE) ? pos - WINDOW_SIZE : 0;

        /* Search earlier text for the longest match.
           The j + length < pos check prevents overlap. */
        for (size_t j = window_start; j < pos; j++) {
            int length = 0;

            while (pos + length < input_len &&
                   j + length < pos &&
                   input[j + length] == input[pos + length]) {
                length++;
            }

            if (length > best_length) {
                best_length = length;
                best_distance = (int)(pos - j);
            }
        }

        if (best_length >= 2) {
            tokens[token_count++] = (Token){
                .is_match = 1,
                .distance = best_distance,
                .length = best_length
            };
            pos += best_length;
        } else {
            tokens[token_count++] = (Token){
                .is_match = 0,
                .literal = input[pos]
            };
            pos++;
        }
    }

    printf("Encoded tokens:\n");
    for (int i = 0; i < token_count; i++) {
        if (tokens[i].is_match) {
            printf("(%d, %d) ", tokens[i].distance, tokens[i].length);
        } else {
            printf("'%c' ", tokens[i].literal);
        }
    }

    /* Decode */
    char output[MAX_INPUT + 1];
    size_t output_len = 0;

    for (int i = 0; i < token_count; i++) {
        if (!tokens[i].is_match) {
            output[output_len++] = tokens[i].literal;
        } else {
            for (int k = 0; k < tokens[i].length; k++) {
                output[output_len] =
                    output[output_len - tokens[i].distance];
                output_len++;
            }
        }
    }

    output[output_len] = '\0';

    printf("\n\nDecoded text: %s\n", output);
    printf("Original text: %s\n", input);

    return 0;
}

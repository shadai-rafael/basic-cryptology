/*
 * Copyright 2019 Shadai Rafael Lopez Garcia
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "caesar_cipher.h"

void test_caesar_cipher_alphabet(void **state)
{
  int result = 0;
  char eng_alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
  char eng_alph_fw2[27] = "cdefghijklmnopqrstuvwxyzab";
  char * cipher_alphabet = NULL;
  char* plain_text = NULL;
  (void)state; /* unsused */

  cipher_alphabet = naive_caesar_cipher(eng_alphabet,26,2);
  result = g_strcmp0((const char *)cipher_alphabet, (const char *) eng_alph_fw2);
  assert_int_equal(result , 0);

  plain_text = naive_caesar_uncipher(cipher_alphabet,26,2);
  result = g_strcmp0((const char *)plain_text , (const char *) eng_alphabet);
  assert_int_equal(result , 0);

  free(plain_text);
  free(cipher_alphabet);
  return;
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_caesar_cipher_alphabet)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

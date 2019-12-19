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
#include <string.h>
#include <stdio.h>
#include <glib.h>

const guint8 upper_char = (guint8)'z';
const guint8 lower_char = (guint8)'a';

int mod (int a, int b)
{
   if(b < 0)
     return -mod(-a, -b);
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

char* naive_caesar_cipher(char * plain_text, guint32 plain_text_len, guint8 key){
  char * cipher_text = NULL;
  int i = 0;
  if(plain_text == NULL)
    return NULL;
  cipher_text = (char *) g_malloc(plain_text_len+1);
  memset(cipher_text, 0 ,plain_text_len+1);
  while(i < plain_text_len){
    plain_text[i] = g_ascii_tolower(plain_text[i]);
    /*for simplicity sake only letters are consider*/
    if(plain_text[i]>='a' && plain_text[i]<='z'){
      cipher_text[i] = mod((plain_text[i] - lower_char+ key) , (upper_char - lower_char+1));
      cipher_text[i] += lower_char;
    }else{
      cipher_text[i] = plain_text[i];
    }
    i++;
  }
  return cipher_text;
}

char* naive_caesar_uncipher(char * cipher_text, guint32 cipher_text_len, guint8 key){
  char * plain_text = NULL;
  int i = 0;
  if(cipher_text == NULL)
    return NULL;
  plain_text = (char *) g_malloc(cipher_text_len+1);
  memset(plain_text, 0 , cipher_text_len+1);
  while(i < cipher_text_len){
    cipher_text[i] = g_ascii_tolower(cipher_text[i]);
    if(cipher_text[i] >= 'a' && cipher_text[i] <= 'z'){
      plain_text[i] =mod( (cipher_text[i] - lower_char - key) , (upper_char - lower_char+1));
      plain_text[i] += lower_char;
    }else{
      plain_text[i] = cipher_text[i];
    }
    i++;
  }
  return plain_text;
}

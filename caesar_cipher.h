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
 #ifndef __CAESAR__
 #define __CAESAR__
 char* naive_caesar_cipher(char * plain_text,
                           guint32 plain_text_len,
                           guint8 key);

 char* naive_caesar_uncipher(char * cipher_text,
                             guint32 cipher_text_len,
                             guint8 key);
 #endif

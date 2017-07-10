Simple math library which utilizes sse/neon intrinsics.

Some test results:

|Intel Core i5-2500                 |Intel Core i3-540                  |Nexus 4                            |
|-----------------------------------|-----------------------------------|-----------------------------------|
|&emsp;&emsp;&emsp;&emsp;**[vec3]** |&emsp;&emsp;&emsp;&emsp;**[vec3]** |&emsp;&emsp;&emsp;&emsp;**[vec3]** |
|&emsp;&emsp;&emsp;**vec3 add**     |&emsp;&emsp;&emsp;**vec3 add**     |&emsp;&emsp;&emsp;**vec3 add**     |
| Ref:   340 ms                     | Ref:   400 ms                     | Ref:   973 ms                     |
| SSE2:  129 ms                     | SSE2:  162 ms                     | NEON:  817 ms                     |
| SSE3:  130 ms                     | SSE3:  157 ms                     |                                   |
| SSE4:  130 ms                     | SSE4:  156 ms                     |                                   |
| AVX:   129 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec3 mul**     |&emsp;&emsp;&emsp;**vec3 mul**     |&emsp;&emsp;&emsp;**vec3 mul**     |
| Ref:   337 ms                     | Ref:   396 ms                     | Ref:   923 ms                     |
| SSE2:  131 ms                     | SSE2:  161 ms                     | NEON:  839 ms                     |
| SSE3:  130 ms                     | SSE3:  163 ms                     |                                   |
| SSE4:  131 ms                     | SSE4:  157 ms                     |                                   |
| AVX:   133 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec3 dot**     |&emsp;&emsp;&emsp;**vec3 dot**     |&emsp;&emsp;&emsp;**vec3 dot**     |
| Ref:   224 ms                     | Ref:   286 ms                     | Ref:   1499 ms                    |
| SSE2:  228 ms                     | SSE2:  250 ms                     | NEON:  1536 ms                    |
| SSE3:  233 ms                     | SSE3:  242 ms                     |                                   |
| SSE4:  227 ms                     | SSE4:  224 ms                     |                                   |
| AVX:   230 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec3 cross**   |&emsp;&emsp;&emsp;**vec3 cross**   |&emsp;&emsp;&emsp;**vec3 cross**   |
| Ref:   394 ms                     | Ref:   425 ms                     | Ref:   1070 ms                    |
| SSE2:  163 ms                     | SSE2:  189 ms                     | NEON:  1062 ms                    |
| SSE3:  167 ms                     | SSE3:  188 ms                     |                                   |
| SSE4:  167 ms                     | SSE4:  187 ms                     |                                   |
| AVX:   165 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec3 len**     |&emsp;&emsp;&emsp;**vec3 len**     |&emsp;&emsp;&emsp;**vec3 len**     |
| Ref:   719 ms                     | Ref:   1114 ms                    | Ref:   4187 ms                    |
| SSE2:  461 ms                     | SSE2:  615 ms                     | NEON:  4111 ms                    |
| SSE3:  460 ms                     | SSE3:  607 ms                     |                                   |
| SSE4:  451 ms                     | SSE4:  609 ms                     |                                   |
| AVX:   449 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec3 norm**    |&emsp;&emsp;&emsp;**vec3 norm**    |&emsp;&emsp;&emsp;**vec3 norm**    |
| Ref:   1337 ms                    | Ref:   1544 ms                    | Ref:   3951 ms                    |
| SSE2:  623 ms                     | SSE2:  645 ms                     | NEON:  3942 ms                    |
| SSE3:  627 ms                     | SSE3:  648 ms                     |                                   |
| SSE4:  639 ms                     | SSE4:  658 ms                     |                                   |
| AVX:   638 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;&emsp;**[vec4]** |&emsp;&emsp;&emsp;&emsp;**[vec4]** |&emsp;&emsp;&emsp;&emsp;**[vec4]** |
|&emsp;&emsp;&emsp;**vec4 add**     |&emsp;&emsp;&emsp;**vec4 add**     |&emsp;&emsp;&emsp;**vec4 add**     |
| Ref:   339 ms                     | Ref:   391 ms                     | Ref:   909 ms                     |
| SSE2:  131 ms                     | SSE2:  158 ms                     | NEON:  821 ms                     |
| SSE3:  130 ms                     | SSE3:  157 ms                     |                                   |
| SSE4:  130 ms                     | SSE4:  156 ms                     |                                   |
| AVX:   131 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec4 mul**     |&emsp;&emsp;&emsp;**vec4 mul**     |&emsp;&emsp;&emsp;**vec4 mul**     |
| Ref:   332 ms                     | Ref:   387 ms                     | Ref:   928 ms                     |
| SSE2:  130 ms                     | SSE2:  157 ms                     | NEON:  826 ms                     |
| SSE3:  132 ms                     | SSE3:  158 ms                     |                                   |
| SSE4:  131 ms                     | SSE4:  156 ms                     |                                   |
| AVX:   129 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec4 dot**     |&emsp;&emsp;&emsp;**vec4 dot**     |&emsp;&emsp;&emsp;**vec4 dot**     |
| Ref:   225 ms                     | Ref:   275 ms                     | Ref:   1558 ms                    |
| SSE2:  230 ms                     | SSE2:  253 ms                     | NEON:  1519 ms                    |
| SSE3:  231 ms                     | SSE3:  243 ms                     |                                   |
| SSE4:  226 ms                     | SSE4:  226 ms                     |                                   |
| AVX:   232 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec4 len**     |&emsp;&emsp;&emsp;**vec4 len**     |&emsp;&emsp;&emsp;**vec4 len**     |
| Ref:   756 ms                     | Ref:   1126 ms                    | Ref:   4734 ms                    |
| SSE2:  459 ms                     | SSE2:  611 ms                     | NEON:  4795 ms                    |
| SSE3:  468 ms                     | SSE3:  608 ms                     |                                   |
| SSE4:  452 ms                     | SSE4:  619 ms                     |                                   |
| AVX:   453 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**vec4 norm**    |&emsp;&emsp;&emsp;**vec4 norm**    |&emsp;&emsp;&emsp;**vec4 norm**    |
| Ref:   853 ms                     | Ref:   1285 ms                    | Ref:   4647 ms                    |
| SSE2:  633 ms                     | SSE2:  607 ms                     | NEON:  4710 ms                    |
| SSE3:  633 ms                     | SSE3:  593 ms                     |                                   |
| SSE4:  637 ms                     | SSE4:  612 ms                     |                                   |
| AVX:   622 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;&emsp;**[mat3]** |&emsp;&emsp;&emsp;&emsp;**[mat3]** |&emsp;&emsp;&emsp;&emsp;**[mat3]** |
|&emsp;&emsp;&emsp;**mat3 add**     |&emsp;&emsp;&emsp;**mat3 add**     |&emsp;&emsp;&emsp;**mat3 add**     |
| Ref:   455 ms                     | Ref:   589 ms                     | Ref:   3686 ms                    |
| SSE2:  242 ms                     | SSE2:  344 ms                     | NEON:  3400 ms                    |
| SSE3:  246 ms                     | SSE3:  343 ms                     |                                   |
| SSE4:  242 ms                     | SSE4:  345 ms                     |                                   |
| AVX:   241 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**mat3 mul**     |&emsp;&emsp;&emsp;**mat3 mul**     |&emsp;&emsp;&emsp;**mat3 mul**     |
| Ref:   605 ms                     | Ref:   834 ms                     | Ref:   4654 ms                    |
| SSE2:  342 ms                     | SSE2:  485 ms                     | NEON:  4228 ms                    |
| SSE3:  341 ms                     | SSE3:  489 ms                     |                                   |
| SSE4:  344 ms                     | SSE4:  483 ms                     |                                   |
| AVX:   344 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**mat3 comp mul**|&emsp;&emsp;&emsp;**mat3 comp mul**|&emsp;&emsp;&emsp;**mat3 comp mul**|
| Ref:   480 ms                     | Ref:   615 ms                     | Ref:   3608 ms                    |
| SSE2:  252 ms                     | SSE2:  347 ms                     | NEON:  3296 ms                    |
| SSE3:  250 ms                     | SSE3:  349 ms                     |                                   |
| SSE4:  246 ms                     | SSE4:  350 ms                     |                                   |
| AVX:   257 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;&emsp;**[mat4]** |&emsp;&emsp;&emsp;&emsp;**[mat4]** |&emsp;&emsp;&emsp;&emsp;**[mat4]** |
|&emsp;&emsp;&emsp;**mat4 add**     |&emsp;&emsp;&emsp;**mat4 add**     |&emsp;&emsp;&emsp;**mat4 add**     |
| Ref:   441 ms                     | Ref:   569 ms                     | Ref:   3412 ms                    |
| SSE2:  292 ms                     | SSE2:  423 ms                     | NEON:  3736 ms                    |
| SSE3:  302 ms                     | SSE3:  419 ms                     |                                   |
| SSE4:  289 ms                     | SSE4:  408 ms                     |                                   |
| AVX:   306 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**mat4 mul**     |&emsp;&emsp;&emsp;**mat4 mul**     |&emsp;&emsp;&emsp;**mat4 mul**     |
| Ref:   1326 ms                    | Ref:   1720 ms                    | Ref:   6706 ms                    |
| SSE2:  546 ms                     | SSE2:  713 ms                     | NEON:  6446 ms                    |
| SSE3:  539 ms                     | SSE3:  724 ms                     |                                   |
| SSE4:  541 ms                     | SSE4:  712 ms                     |                                   |
| AVX:   371 ms                     |                                   |                                   |
|&emsp;&emsp;&emsp;**mat4 comp mul**|&emsp;&emsp;&emsp;**mat4 comp mul**|&emsp;&emsp;&emsp;**mat4 comp mul**|
| Ref:   504 ms                     | Ref:   647 ms                     | Ref:   3595 ms                    |
| SSE2:  308 ms                     | SSE2:  416 ms                     | NEON:  3490 ms                    |
| SSE3:  307 ms                     | SSE3:  404 ms                     |                                   |
| SSE4:  308 ms                     | SSE4:  408 ms                     |                                   |
| AVX:   297 ms                     |                                   |                                   |

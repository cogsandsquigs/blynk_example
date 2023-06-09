# blynk_example

This is a simple example of how to use the Blynk library with the Particle Argon.

## Getting Started

You will need to create a file in `src` called `env.h`, which is where your Blynk template id, name and auth token will be stored. This file is ignored by git, so you don't have to worry about accidentally committing it.

For example, if your template id is `abc123`, its name is `test template`, and your auth token is `1234567890abcdef`, you would create `src/env.h` with the following contents:

```h
#ifndef ENV_H

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "abc123"
#define BLYNK_TEMPLATE_NAME "test template"
#define BLYNK_AUTH_TOKEN "1234567890abcdef"

#endif
```

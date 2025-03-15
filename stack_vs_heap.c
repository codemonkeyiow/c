typedef struct {
    int someInteger;
    char someArray[8];
    char *somePointer;
  } Item;

  void someFunction(void)
  {
    Item foo; /* This is on the stack */

     /*
      * This is a pointer. The pointer itself lives on the stack.
      * It doesn't actually point _to_ anything yet though,
      * it is uninitialized.
      */
    Item *fooP;

    fooP = &foo; /* Now it's a pointer to the foo on the stack! */

    /*
     * That means all of the members are on the stack.
     * someArray is _directly_ on the stack as a part of the Item.
     * somePointer, again - the pointer itself is on the stack as a
     * part of Item. It doesn't point to anything yet. It is uninitialized.
     */

    fooP->somePointer = "abcde";
    /* Now somePointer points to global data - neither on the stack nor the heap */

    fooP->somePointer = strdup("abcde");
    /*
     * Now it points to a string on the heap!
     * (strdup is a shortcut for malloc() + strcpy()
     */

    strncpy(fooP->someArray, "fghijk", sizeof (fooP->someArray));
    /* Now our someArray, on the stack, contains those letters. */

    fooP = malloc(sizeof (Item));
    /*
     * But hey, now fooP is a pointer to a foo on the heap!
     * That `foo` on the stack is still there though. We just pointed the pointer somewhere else.
     */
  }

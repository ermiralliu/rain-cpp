#### 10 Jul 2024:
```
Removed init and fixed the constructors to initialize correctly
-This way, the object is pretty much always valid
removed clean and moved it all to the destructor
-You never need to clean an object, you can just take it out of scope 
or assign another object to it. This way it can never be invalid
moved SDL_initializer to main
--game takes care of destroying it (maybe it could've been put in a better place but idc). 
```
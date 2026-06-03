Part of this project was built with AI.
Percentage of AI code is around 30-40%, which is a lot, and there is no excuse that can ovecome that.

I started this project to help me understand more of the ESP32's API/commands, and to learn more of C/C++.
While building the basics of Espirit, I asked codex for help in udesrtanding on how to add a feature i wanted to add, after that I accidentaly deleted every file I had, because I wanted to delete the ugly green git color. Codex rebuilt every file from what it remembered, if it wasn't recovered by me.
All of the work was made on top of those remaked scripts, and almost none of that code remained because of issues in the code which I had to resolve rewriting everything for the thing to just start loading up again.

Addition: I had some issues when adding images;
When i first added the image loading things, it worked, until I tried loading images with a bit over 3500 commands, it crashed.
That issue started a chain of events, where inevitably PSRAM wouldn't initialize **before** the app start, which when I finnaly had given up and handed it over codex, it also tried very hardly resolving that for a long time.
(But it was worth it, now you can load really large images)

I am very sorry for using AI in this,
but atleast it finally works?

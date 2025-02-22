# “Hoes Mad” cover but there are all possible permutations of the catch phrase [shitpost]

## Final result

YouTube: [Ladies Irrational - Famous Dex (feat. Suno) | AI Cover](https://youtu.be/ZHc1tSfek4A)

## Chapter 1. Prelude.

This stupid idea came to us while we were day drinking and smoking cigarettes with my friends back in 2020. We were watching some meme compilation and remembered the existence of viral meme song Hoes Mad by Famous Dex from the 2016 album Dexter's Laboratory.

We though “this is too repetitive, wouldn’t it be nice to use synonyms for those words?”, so I pulled out C++, googled some synonyms and generated a list of all possible permutations of those two lists (`11 * 45 = 495 combinations`).

<p align="center">
  <img src="https://user-images.githubusercontent.com/82185066/164068435-5d605585-fe83-4b7f-ac9b-4e30ded218a0.png" alt="Program output">
</p>

Full program output can be seen on the [Wiki page](https://github.com/ebolblga/Ladies-Irrational/wiki).

Next step would have been somehow making a cover for the original song with newly generated lyrics, however none of us could sing (especially this gibberish mess of lyrics) and synthesizing voice at that time was mostly used as a joke and it definitely could not be used for making music.

<p align="center">
  <img src="https://github.com/user-attachments/assets/71919241-c02d-4455-bfc2-01ca5940283c" alt="I'm limited by the technology of my time meme">
</p>

## Chapter 2. Generative AI boom.

5 years later I was scrolling through my GitHub repos and came across this forbidden project. Obviously I realised that it is time, it is time to finish the shitpost. So I explored latest state-of-the-art models used for synthesizing someone's voice and singing with that voice. Keep in mind that I’m not a musician and this is my first and possibly last time generating a song, so take whatever I say with a grain of salt. But here is the pipeline I came up with for making something like this.

### 2.1. Gathering assets

I downloaded [original song](https://youtu.be/J6oTIjvw_-8) from YouTube and got its lyrics from [Genius](https://genius.com/Famous-dex-hoes-mad-lyrics). Next I modified my program to scramble list of permutations so they are not ordered.

Famous Dex said “hoes mad” in that song exactly `77` times (not counting ad-libs in the background) so I had to narrow down my list quite a bit.

Just in case I also used [Vocal Remover](https://vocalremover.org/) to separate vocals from music. It is free to use but has a daily quota. This got really handy in the future.

### 2.2. Generating the song

Next step would be generating the song, and there are multiple ways you can do it, I will talk about each one.

#### 2.2.1. Plan A - best result

This way of making cover with different lyrics is way more complicated but gives you the best results in the end. Spoilers - I did not use it.
You can use this open source project [Retrieval-based-Voice-Conversion-WebUI](https://github.com/RVC-Project/Retrieval-based-Voice-Conversion-WebUI) to train a voice model of any person you want with a sample length of less than 10 minutes. Next you sing the song with your voice or hire some singer from [Fiverr](https://www.fiverr.com/gigs/commission) and later change the voice to the artist you need. This produces actually good results and you will have full control of how the songs gets sang, obviously because there is a human doing it.

#### 2.2.2. Plan B - not free

There is a service called [Udio](https://www.udio.com/), using “extend song” feature may allow you to make covers for songs with original song singer, however recently they have hidden that feature behind a paywall.

#### 2.2.3. Plan C - my approach

I didn’t want to sing or pay someone else, so I came up with a different pipeline.

[Suno](https://suno.com/) is quite similar to Udio, however extend song feature is available in the free plan, I uploaded 30 seconds of vocals from the original song, pasted in the lyrics with additional markers like: [Chorus], [Verse 1], [Verse 2] etc. and clicked extend song.

It generated its own music as well as vocals singing my lyrics, although with some hallucinations and noise. So I downloaded generated song, again used Vocal Removed to get vocals track and booted up [Audacity](https://www.audacityteam.org/) to compose final song. Cleaned it up a bit, cut it up with the original song and exported as 360kbps stereo MP3 file.

<p align="center">
  <img src="https://github.com/user-attachments/assets/25be0b5f-5e41-4510-a99b-2ebf45080048" alt="Audacity viewport">
</p>

## Chapter 3. Conclusion.

As of today, it’s really easy to change voice in a song or even generate a new one, however when it comes to taking an existing song and just changing its lyrics it’s a pretty challenging task. I think the technology is not quite there yet but in a window of 5 years we will definitely have the solution.

Final result of my experiment is alright, although you can clearly hear when it’s generated voice and when it’s original voice, but as a quick shitpost - it works.

## License
This program is licensed under the MIT License. Please read the License file to know about the usage terms and conditions.

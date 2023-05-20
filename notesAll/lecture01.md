<!--graphics, faculty, equivalent, EE and CS major in MIT, does make that alignment; Yugoslacia, Serbia, Belgrade, expressive, enthusiastic, and electrons filling holes, how to peek below the hood, regulate, arguably, transistors,gory,obfuscating, wires, microprocessor, corporation, corollary, inflation, vilified, retrieve, chip-->

![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 20.45.25.png)



![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 20.46.59.png)



![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 21.06.51.png)



<!--Campus, sacramento, pluto, tape/optical robot, Andromeda-->

Getting something from the registers that are on the microprocessor chip takes approximately a nanosecond.

Sacramento is an equivalent of going to the memory, going from the microprocessor chip to the DRAM chip, which is a separate chip on a computer motherboard.

Going to a magnetic disk is like going to Pluto. Going to a solid state disk is kind of going to Mars. Not a big difference from that standpoint.

Get to a tape or an optical robot that is doing backups, well, that's like kind of going to another galaxy.

![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 21.19.21.png)

You live at the speed of the small, fast guy, but you actually get the abstract view with the size of the bigger guy.

<!--drilling-->

![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 21.26.14.png)

Amdahl, the longest pole on this tent will always stick out.

If we have 50% of parallel code, that means that the other 50% of our code is serial code.

If we try to parallelize to infinity this parallel code, that means that the total speed up is only going to be up to 50% because now the serial code is going to be the bottleneck.

We will always work on squishing something that we can accelerate and make fast, but then we have to worry about the other things that pop up.

4. 

<!--Dave Patterson, our emeritus, quantify the metrics of compute system, exploit-->

Latency: how long to complete a task

Throughput: how many tasks can be completed in given time.

5. <!--cloud chamber-->

The cloud chamber basically records hits of cosmic rays onto the Earth into this. So we see some ionization happening there. These little traces that we see on the slide are essentially charged particles that are hitting a chamber over there. They hit us all the time. They hit our chips. So even if we build everything redundant, these things are going to rain on us. And they have been raining since the Big Bang on everything that is out there in the space. They have a tendency or ability to flip bits. And bits that used to be 0 may become ones. And those that were ones may become zeros. And that's not going to look good, for example, on somebody's bank account, especially if one gets flipped to a zero. So many of these compute systems need to be made very dependable in that. This is now a really popular topic when you talk about self-driving because there are certain standards that these new systems need to meet there.

6. Redundancy so that a failing piece doesn't make the whole system fail.

Redundant datacenters, 

redundant disks and RAID systems which basically means redundant arrays of independent disks,  

DIMM,which is DRAM, represent 8-bit words, but nine chips.

<!--amorphous, telemedicine, autonomous driving, -->

Number of deployed device continues to grow, require to be implemented specialized systems. Now because of Moore's law slowing down, this becomes an architecture issue. What we find machine learning is common for most domains nowadays, but it is not the killer app. The killer app is to make the car drive use the machine learning to make that happen.

![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 22.08.46.png)

We are still getting more <u>transistors</u>, but they are <u>not coming that easily</u> and that abundantly as they did before. So the other thing - <u>power</u> has been limiting many of the chips. So in order to limit the power increase - otherwise, we will be running little furnaces in front of us - <u>the frequency had to be limited</u>. <u>Single thread performance</u> was <u>tied to the frequency</u>. In order to get better performance, we went <u>parallel</u>. So we saw the <u>number of cores increasing.</u> But what hs been observed now - there is a limited amount of parallelism that is out there because of <u>Amdahl's law</u>. So what do we do now to get more compute performance? That's the idea of specialization. 

![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 22.13.25.png)

That is why we are seeing a lot of development of these heterogeneous differentiated systems for different compute domains. 

Here is Apple A13 Bionic that has multiple microprocessor cores on it and then has specialized units like GPUs (graphics processing units), and now has a neural processing unit and a whole bunch of things that are unlabeled here. 

![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 22.23.57.png)



![](/Users/a/Documents/pictures-for-cs61c/截屏2023-04-10 22.25.44.png)

Hot Chips Conference. It has four liquid cooled chips, That thing, when put in the racks, that can deliver over 100 peta floating point operations per second.



Dan: One of the things that Patterson and Hennessey did was they went against conventional wisdom. <!--更少的指令集？-->

Patterson & Hennessy, *Computer Organization and Design*，RISC-V ed

Kernighan & Ritchie, <u>The C Programming Language</u>, 2nd

Barroso & Holzle, <u>The Datacenter as a Computer</u>, 3rd
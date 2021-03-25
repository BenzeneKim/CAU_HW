physicalPain = bool(input("set the physical pain status"))
painDegree = int(input("set the degree of pain(0~9)"))
PNSstatus = int(input("Set the PNS status(0,1,2)"))
CNSstatus = int(input("set the CNS status(0,1,2)"))



painStatus = [physicalPain, painDegree, PNSstatus, CNSstatus]

if painStatus[0]:
    if painStatus[1] > 5:
        print("The pain signal sensed by a neciceptor was sent through the CNS")
        print("The pain signal was arrived to the PNS")
        print("I can feel the sensory pain")
    else:
        print("There's no pain")
else:
    if painStatus[2]*painStatus[3] != 0:
        if painStatus[2] != 0:
            if painStatus[2] == 1:
                print("I can feel the phatom pain")
            else:
                print("I can feel the neurological pain")
        else:
            if painStatus[3] == 1:
                print("I can feel the sensory pain")
            else:
                print("I can feel the neurological pain")
    else:
        print("I can feel the emotional pain")


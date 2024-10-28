import random

def find_fake_box():
    real_weight = 10  # weight of a real piece of metal
    fake_weight = 9  # weight of a fake piece of metal
    boxes = [[real_weight]*50 for _ in range(50)]  # all boxes initially have real pieces

    fake_box = random.randint(0, 49)  # randomly select a box to contain fake pieces
    boxes[fake_box] = [fake_weight]*50  # replace real pieces with fake pieces in the selected box

    expected_weight = sum(range(1, 51)) * real_weight  # assuming all pieces are real
    actual_weight = sum(i * boxes[i-1][0] for i in range(1, 51))  # total weight of pieces

    return expected_weight - actual_weight + 1  # box number with fake pieces

# Test the function
print(find_fake_box())  # outputs: the number of the box with fake pieces


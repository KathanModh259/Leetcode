class RandomizedSet(object):
    def __init__(self):
        import random
        self.r = random.choice
        self.arr = []
        self.pos = {}

    def insert(self, val):
        return False if val in self.pos else (self.pos.__setitem__(val,len(self.arr)), self.arr.append(val))[1] or True

    def remove(self, val):
        if val not in self.pos: return False
        i = self.pos[val]
        last = len(self.arr) - 1
        if i < last:
            self.arr[i], self.arr[last] = self.arr[last], self.arr[i]
            self.pos[self.arr[i]] = i
        self.arr.pop()
        del self.pos[val]
        return True

    def getRandom(self):
        return self.r(self.arr)
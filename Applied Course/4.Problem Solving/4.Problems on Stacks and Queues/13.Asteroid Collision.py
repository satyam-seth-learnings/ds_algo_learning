# https://leetcode.com/problems/asteroid-collision
# Logic-1
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result=[]
        for new in asteroids:
            while result and new<0<result[-1]:
                if result[-1]<abs(new):
                    result.pop()
                    continue
                elif result[-1]==abs(new):
                    result.pop()
                break
            else:
                result.append(new)
        return result
# Logic-2
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        i=-1
        for j in range(len(asteroids)):
            while i>=0 and asteroids[i]>=0 and asteroids[j]<0:
                if asteroids[i]<abs(asteroids[j]):
                    i-=1
                    continue
                elif asteroids[i]==abs(asteroids[j]):
                    i-=1
                break
            else:
                asteroids[i+1]=asteroids[j]
                i+=1
        return asteroids[:i+1]
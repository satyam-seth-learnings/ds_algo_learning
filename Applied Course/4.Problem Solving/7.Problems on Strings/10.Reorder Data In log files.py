class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digit_logs,letter_logs=[],[]
        for log in logs:
            second_word=log.split()[1]
            if second_word.isdigit():
                digit_logs.append(log)
            else:
                letter_logs.append(log)
        letter_logs.sort(key=lambda x:x.split()[0])
        letter_logs.sort(key=lambda x:x.split()[1:])
        return letter_logs+digit_logs
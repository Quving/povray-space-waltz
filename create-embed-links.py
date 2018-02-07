#!/usr/bin/env python3

def mmss2s(mmss: str):
    mm, ss = mmss.split(':')
    return int(mm) * 60 + int(ss)

url = "https://www.youtube.com/embed/xyjOjT8d8RI?start={}&end={}"

times = [
    ('0:00', '0:13'),
    ('0:13', '0:23'),
    ('0:23', '0:31'),
    ('0:31', '0:56'),
    ('0:56', '1:25'),
    ('1:25', '1:45'),
    ('1:45', '2:04'),
    ('2:04', '2:12'),
    ('2:12', '2:22'),
    ('2:22', '2:28'),
    ('2:28', '2:45'),
    ('2:45', '2:55'),
    ('2:55', '3:02'),
    ('3:02', '3:31'),
    ('3:31', '3:41'),
    ('3:41', '3:48'),
    ('3:48', '4:30'),
    ('4:30', '4:49'),
    ('4:49', '5:00'),
    ('5:00', '5:21'),
]

for t in times:
    start_in_s = mmss2s(t[0])
    end_in_s = mmss2s(t[1])
    print(url.format(start_in_s, end_in_s))


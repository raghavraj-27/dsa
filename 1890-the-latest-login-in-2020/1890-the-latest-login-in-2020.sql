# Write your MySQL query statement below
# select user_id, time_stamp
# from logins
# where TO_DAYS('2020-12-31') - TO_DAYS(time_stamp) < 367 and TO_DAYS('2020-12-31') - TO_DAYS(time_stamp) > 0
# select user_id, time_stamp
# from logins
# # group by user_id
# where time_stamp in (select max(time_stamp) from logins 
#                      where TO_DAYS('2020-12-31') - TO_DAYS(time_stamp) < 367 and TO_DAYS('2020-12-31') - TO_DAYS(time_stamp) > 0)
                     
select user_id, max(time_stamp) as last_stamp
from logins 
where YEAR(time_stamp) = 2020
group by user_id

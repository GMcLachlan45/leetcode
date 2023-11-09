# Runtime: 502ms
# Memory: 60.91MB
import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    doubled_salary = 2*employees.loc[: , 'salary']
    employees.update(doubled_salary)
    return employees

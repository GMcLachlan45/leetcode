# Runtime: 455ms
# Memory: 60.40MB
import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.assign(bonus=lambda x: x.salary * 2)

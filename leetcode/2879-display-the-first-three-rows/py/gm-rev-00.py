# Runtime: 585ms
# Memory: 59.92MB
import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)

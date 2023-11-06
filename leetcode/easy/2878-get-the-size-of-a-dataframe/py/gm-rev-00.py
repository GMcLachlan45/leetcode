# Runtime: 493ms
# Memory: 59.43MB
import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)

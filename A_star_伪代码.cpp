把起始格添加到 "开启列表" 
do 
{ 
        寻找开启列表中F值最低的格子, 我们称它为当前格. 
        把它切换到关闭列表. 
        对当前格相邻的8格中的每一个 
        if (它不可通过 || 已经在 "关闭列表" 中) 
        { 
                什么也不做. 
        } 
        if (它不在开启列表中) 
        { 
                把它添加进 "开启列表", 把当前格作为这一格的父节点, 计算这一格的 FGH 
        }
        if (它已经在开启列表中) 
        { 
                if (用 G 值为参考检查新的路径是否更好, 更低的G值意味着更好的路径) 
                { 
                        把这一格的父节点改成当前格, 并且重新计算这一格的 GF 值. 
                } 
        }
} while( 目标格已经在 "开启列表", 这时候路径被找到) 
如果开启列表已经空了, 说明路径不存在.
 
最后从目标格开始, 沿着每一格的父节点移动直到回到起始格, 这就是路径.
/*在第一次迭代中，我们将每个元素的值和它的索引添加到表中。
然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target−nums[i]）是否存在于表中。
注意，该目标元素不能是 nums[i] 本身！*/



//hash_data存储的是数组下标和数组元素，next指针指向hash_table中对应键值(k=|nums[i]|%100)的指针数组head
//hash_table中指针数组head[k]的元素指向对应hash_data的地址，k为键值(|nums[i]|%100)


//map 的简单实现
struct hash_data{
    int key;//num[i]
    int data;//i
    struct hash_data * next;//指向head[k],k=|nums[i]|%100
};

 struct hash_table
{
    struct hash_data ** head; //指针数组,指向对应的hash_data地址
    int hash_width;
};

///初始化
int hash_init(struct hash_table * table, int width){
    if(width<=0)
        return -1;
    struct hash_data **tmp = (struct hash_data **)malloc(sizeof(struct hash_data *)*width);//分配width(100)个struct hash_data *的空间，未分开void类型
    table->head = tmp;//
    memset(table->head, 0, width * sizeof(struct hash_data *));//空间置0
    if(table->head==NULL)
        return -1;//空间不足，返回-1，结束
    table->hash_width = width;//哈希表长度
    return 0;//成功，返回0
}



///释放
void hash_free(struct hash_table table){
    if(table.head!=NULL){
        for (int i=0; i<table.hash_width; i++) {
            struct hash_data* element_head= table.head[i];
            while (element_head !=NULL) {
                struct hash_data* temp =element_head;
                element_head = element_head->next;
                free(temp);
            }
        }
        free(table.head);
        table.head = NULL;
    }
    table.hash_width = 0;
}




int hash_addr(struct hash_table table,int key){		//哈希函数
    int addr =abs(key) % table.hash_width;          //|nums[i]|mod100
    return addr;									//返回|nums[i]|mod100
}

///增加
//插入操作，原来table.head[k]里放着b，现在新建一个结点a，让a的next为b，然后让table.head[k]里放的是a。
//这样是因为有可能两个不同data的key一样，解决冲突。
int hash_insert(struct hash_table table,int key, int value){
    struct hash_data * tmp = malloc(sizeof(struct hash_data));//tmp指向一段void类型struct hash_data空间,每次都分配一个新的结构体空间			
    if(tmp == NULL)															//******************************************//
        return -1;//空间不足，返回-1，结束									//			存储在hash_data结构体中			//
    tmp->key = key;//nums[i]												//											//
    tmp->data = value;//数组下标i											//******************************************//
    int k = hash_addr(table,key);//k为经哈希函数后的键值					//											//
    tmp->next =table.head[k];												//			存储在hash_table结构体中		//
    table.head[k]=tmp;														//											//
    return 0;																//******************************************//
}


///查找
struct hash_data* hash_find(struct hash_table table, int key){//key= target - nums[i]
    int k = hash_addr(table,key);
    struct hash_data* element_head=table.head[k];//element_head指向table.head[k]内hash_data地址
    while (element_head !=NULL) {//element_head指向table.head[k]内hash_data地址不为空，即表示有此项数据
        if ( element_head->key == key) {
            return element_head;//值相等即返回hash_data地址
        }
        element_head = element_head->next;//值不相等？？？？？？？？？？？？？？？？？？？？？？？？？？？
    }
    return NULL;//没有对应元素返回NULL
}



///依赖map实现
//一遍与二遍哈希表的主要差别在此
//一遍与二遍哈希表时间复杂度与空间复杂度相同均为O(N)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int *)malloc(sizeof(int) * 2);//为2个i分配内存
    * returnSize=0;//返回元素个数
    struct hash_table table;//创建哈希表
    hash_init(&table, 100);//给哈希表分配100个内存单元
    for (int i=0; i<numsSize; i++) {//将数组内的元素和下标存入hash_data，将对应的hash_data地址和键值存入hash_table
        hash_insert(table,nums[i] ,i);
    }
    
    for(int i = 0; i < numsSize; i++)
    {
        int value = target - nums[i];
        struct hash_data* data=  hash_find(table, value);
        if (data !=NULL && data->data != i) {
            res[1]=i;//一个i
            res[0]=data->data;//另一个i
            * returnSize=2;//返回元素个数为2
        }
    }
    hash_free(table);//释放内存
    return res;//返回两个i
}

作者：chen-xing-15
链接：https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-san-chong-jie-fa-by-chen-xing-15/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
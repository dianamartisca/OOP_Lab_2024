//#include<cstdio>

template<typename K, typename V>
class Map
{
	struct Obj
	{
		K key;
		V value;
		int index;
	} *obj;
	int k;
public:
	Map()
	{
		obj = new Obj[100];
		k = 0;
	}
	const Obj* begin()
	{
		return &obj[0];
	}
	const Obj* end()
	{
		return &obj[k];
	}
	V& operator[](K cheie)
	{
		int i;
		for (i = 0; i < k; i++)
			if (obj[i].key == cheie)
				return obj[i].value;
		obj[k].key = cheie;
		obj[k].index = k;
		k++;
		return obj[k - 1].value;
	}
	void Set(const K& cheie, const V& val)
	{
		int i;
		for (i = 0; i < k; i++)
			if (obj[i].key == cheie)
				obj[i].value = val;
		if (i == k)
		{
			obj[k].key = cheie;
			obj[k].index = k;
			obj[k].value = val;
			k++;
		}
	}
	bool Get(const K& key, V& value)
	{
		int i;
		for (i = 0; i < k; i++)
			if (obj[i].key == key)
			{
				value = obj[i].value;
				return true;
			}
		return false;
	}
	int Count()
	{
		return k;
	}
	void Clear()
	{
		delete[] obj;
		k = 0;
	}
	bool Delete(const K& key)
	{
		int i, j;
		for (i = 0; i < k; i++)
			if (obj[i].key == key)
			{
				for (j = i; j < k - 1; j++)
					obj[j] = obj[j + 1];
				k--;
				return true;
			}
		return false;
	}
	bool Includes(const Map<K, V>& map)
	{
		if (map.k > k)
			return false;
		int i, j;
		for(i=0;i<map.k;i++)
		{
			int ok = 0;
			for(j=0;j<k;j++)
				if (map.obj[i].key == obj[j].key)
				{
					ok = 1;
					break;
				}
			if (!ok)
				return false;
		}
		return true;
	}
};
class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

		int num_crit = buildings.size() * 2;
		vector<pair<int, int>> crit;

		for (int i = 0; i < buildings.size(); i++) {

			crit.push_back(make_pair(buildings.at(i).at(0), buildings.at(i).at(2)));
			crit.push_back(make_pair(buildings.at(i).at(1), 0));

		}

		sort(crit.begin(), crit.end());

		for (int j = 0; j < num_crit; j++) {

			int x = get<0>(crit.at(j));
			int h = get<1>(crit.at(j));

			for (int k = 0; k < buildings.size(); k++) {

				if (x >= buildings.at(k).at(0) && x < buildings.at(k).at(1)) {

					if (buildings.at(k).at(2) > h) {
						h = buildings.at(k).at(2);
					}

				}

			}

			crit.at(j) = make_pair(x, h);

		}

		vector<vector<int>> res;
		int hl = 0;
		vector<int> point;

		for (int l = 0; l < num_crit; l++) {

			cout << "x : " << get<0>(crit.at(l)) << " h : " << get<1>(crit.at(l)) << endl;

			if(get<1>(crit.at(l)) != hl) {

				hl = get<1>(crit.at(l));
				point.clear();
				point.push_back(get<0>(crit.at(l)));
				point.push_back(hl);
				res.push_back(point);

			}

		}

		return res;

	}
};
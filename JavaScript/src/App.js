import React, { useState } from 'react';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Home from './components/Home';
import UserProfile from './components/UserProfile';
import Login from "./components/Login";
import Debit from './components/Debit';
import Credit from './components/Credit';

function App() {

  const [accountBalance, setAccountBalance] = useState(420.69)
  const [currentUser, setCurrentUser] = useState({ userName: "gianna", memberSince: '04/20/69' })
  const mockLogIn = (logInInfo) => {
    const newUser = { ...currentUser }
    newUser.userName = logInInfo.userName
    setCurrentUser(newUser)
  }
  function updateAccountBalance(amount) {
    const newBalance = accountBalance - amount
    setAccountBalance(newBalance)
  }


  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home accountBalance={accountBalance} />} />
        <Route path="/userProfile" element={<UserProfile userName={currentUser.userName} memberSince={currentUser.memberSince} />} />
        <Route path="/login" element={<Login user={currentUser} mockLogIn={mockLogIn} />} />
        <Route path="/debit" element={<Debit accountBalance={accountBalance} updateAccountBalance={updateAccountBalance} />} />
        <Route path="/credit" element={<Credit accountBalance={accountBalance} updateAccountBalance={updateAccountBalance} />} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;
import React from 'react';
import AccountBalance from './AccountBalance';
import { Link } from 'react-router-dom';

function Home(props) {
    return (
        <div>
            <img src="https://res.cloudinary.com/andreahabib/image/upload/v1642026304/React_Bank_dk7n1a.png" alt="bank" />
            <h1>Bank of React</h1>

            <Link to="/userProfile">User Profile</Link>
            <br />
            <Link to="/Debit">Debit</Link>
            <br />
            <Link to="/Credit">Credit</Link>

            <AccountBalance accountBalance={props.accountBalance} />
        </div>
    );
}

export default Home;
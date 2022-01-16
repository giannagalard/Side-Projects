import React, { useState } from 'react'
import { Navigate } from 'react-router-dom'

function LogIn(props) {

    const [user, setUser] = useState({ userName: "", password: "" }) // initial state
    const [redirect, setRedirect] = useState(false) // initial state


    const handleChange = (e) => {
        const updatedUser = { ...user } // copy current state
        const inputField = e.target.name // get name of input field
        const inputValue = e.target.value // get value of input field
        updatedUser[inputField] = inputValue // update state

        setUser(updatedUser) // update state
    }

    const handleSubmit = (e) => {
        e.preventDefault() // prevent default form submission behavior (page reload) 
        props.mockLogIn(user) // mock login function from parent component
        setRedirect(true) // set redirect state to true
    }

    if (redirect) {
        return (<Navigate to="/userProfile" />) // redirect to user profile page
    }

    // dont submit as a form, just submit
    return (
        <div>
            <form onSubmit={handleSubmit}>
                <div>
                    <label htmlFor="userName">User Name</label>
                    <input type="text" name="userName" onChange={handleChange} value={user.userName} />
                </div>
                <div>
                    <label htmlFor="password">Password</label>
                    <input type="password" name="password" />
                </div>
                <button>Log In</button>
            </form>
        </div>
    )
}

export default LogIn